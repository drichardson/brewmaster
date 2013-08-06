package main

import (
    "fmt"
	"io"
//    "io/ioutil"
    "os"
	"net/http"
    "encoding/json"
	"database/sql"
	"github.com/bmizerany/pat"
    "github.com/coocood/qbs"
    _ "github.com/mattn/go-sqlite3"
	"log"
)

// hello world, the web server
func HelloServer(w http.ResponseWriter, req *http.Request) {
	io.WriteString(w, "hello, "+req.URL.Query().Get(":name")+"!\n")
}

// *** DB ***
var SharedProxy *qbs.Qbs

var dbName string = "./beer.db"

func OpenDb() bool {

    // Open DB
	db, err := sql.Open("sqlite3", dbName)
	q := qbs.New(db, qbs.NewSqlite3())
    if err != nil {
        return false
    }

    // Run Migrations
    mg := SetMg(db);
    mg.CreateTableIfNotExists(new(Beverage))

    // Track Singleton
    SharedProxy = q
    return true
}

func CloseDb() {
    SharedProxy.Db.Close()
}

func SetMg(db *sql.DB) (*qbs.Migration) {
	mg := qbs.NewMigration(db, dbName, qbs.NewSqlite3())
	return mg
}

// *** Utils ***
func ReadFromJson(r io.Reader, m interface{}) error {
    decoder := json.NewDecoder(r)
    err := decoder.Decode(&m)
    return err
}

func WriteToJson(w io.Writer, m interface{}) error {
    encoder := json.NewEncoder(w)
    err := encoder.Encode(&m)
    return err
}

// *** Beverage ***
type Beverage struct {
    Id string `qbs:"pk"`
    Name string// `qbs:"size:255,index"`
}

func findBeverageById(id string) (*Beverage, error) {
    b := new(Beverage)
	b.Id = id

	err := SharedProxy.Find(b)
    return b, err
}

func PostBeverage(w http.ResponseWriter, req *http.Request) {
    var b Beverage
    err := ReadFromJson(req.Body, &b)
    if err != nil {
        fmt.Printf("Beverage Body err: %v\n", err)
    }

    _, sErr := SharedProxy.Save(&b)
    if sErr != nil {
        fmt.Printf("Beverage save err: %v\n", sErr)
    }
}

func GetBeverage(w http.ResponseWriter, req *http.Request) {
    reqId := req.URL.Query().Get(":id")
    b, err := findBeverageById(reqId)
    if err != nil {
        fmt.Printf("Beverage read err: %v\n", err)
    }

    wErr := WriteToJson(w, b)
    if wErr != nil {
        fmt.Printf("Beverage write err: %v\n", err)
    }
}

func PutBeverage(w http.ResponseWriter, req *http.Request) {
    var b Beverage
    err := ReadFromJson(req.Body, &b)
    if err != nil {
        fmt.Printf("Beverage Body err: %v\n", err)
    }

    reqId := req.URL.Query().Get(":id")
    _, fErr := findBeverageById(reqId)
    if fErr != nil {
        SharedProxy.Save(b)
    } else {
        SharedProxy.Update(b);
    }

    wErr := WriteToJson(w, b)
    if wErr != nil {
        fmt.Printf("Beverage write err: %v\n", err)
    }
}

func DelBeverage(w http.ResponseWriter, req *http.Request) {
    reqId := req.URL.Query().Get(":id")
    b, err := findBeverageById(reqId)
    if err != nil {
        fmt.Printf("Beverage Body err: %v\n", err)
    } else {
        SharedProxy.Delete(b)
    }
    // Write response?
}


// *** Producer ***
func PostProducer(w http.ResponseWriter, req *http.Request) {
}

func GetProducer(w http.ResponseWriter, req *http.Request) {
}

func PutProducer(w http.ResponseWriter, req *http.Request) {
}

func DelProducer(w http.ResponseWriter, req *http.Request) {
}

// *** Monitor ***
func PostMonitor(w http.ResponseWriter, req *http.Request) {
}

func GetMonitor(w http.ResponseWriter, req *http.Request) {
}

func PutMonitor(w http.ResponseWriter, req *http.Request) {
}

func DelMonitor(w http.ResponseWriter, req *http.Request) {
}


func main() {

    // FOR TESTING
    os.Remove(dbName)

	m := pat.New()

    m.Get("/test/:name", http.HandlerFunc(HelloServer))

	m.Post("/beverage/:id", http.HandlerFunc(PostBeverage))
	m.Get("/beverage/:id", http.HandlerFunc(GetBeverage))
	m.Put("/beverage/:id", http.HandlerFunc(PutBeverage))
	m.Del("/beverage/:id", http.HandlerFunc(DelBeverage))

	m.Post("/producer/:id", http.HandlerFunc(PostProducer))
	m.Get("/producer/:id", http.HandlerFunc(GetProducer))
	m.Put("/producer/:id", http.HandlerFunc(PutProducer))
	m.Del("/producer/:id", http.HandlerFunc(DelProducer))

	m.Post("/monitor/:id", http.HandlerFunc(PostMonitor))
	m.Get("/monitor/:id", http.HandlerFunc(GetMonitor))
	m.Put("/monitor/:id", http.HandlerFunc(PutMonitor))
	m.Del("/monitor/:id", http.HandlerFunc(DelMonitor))

    OpenDb()

	// Register this pat with the default serve mux so that other packages
	// may also be exported. (i.e. /debug/pprof/*)
	http.Handle("/", m)
	err := http.ListenAndServe(":12345", nil)
	if err != nil {
		log.Fatal("ListenAndServe: ", err)
	}

}


