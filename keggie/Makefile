BUILD_DIR=build
NATIVE_DIR=$(BUILD_DIR)/native
KEGGIE_APP=./build/native/keggie.app/keggie

native: 
	[ -d "$(NATIVE_DIR)" ] || mkdir -p "$(NATIVE_DIR)"
	cd "$(NATIVE_DIR)" && cmake ../..
	cd "$(NATIVE_DIR)" && make

run: native
	$(KEGGIE_APP)

debug: native
	gdb $(KEGGIE_APP)

cscope:
	cscope -Rb src/*

clean:
	$(RM) -r $(BUILD_DIR) cscope.out
