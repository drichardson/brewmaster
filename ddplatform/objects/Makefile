BUILD_DIR=build
NATIVE_DIR=$(BUILD_DIR)/native
XCODE_DIR=$(BUILD_DIR)/xcode

native: 
	[ -d "$(NATIVE_DIR)" ] || mkdir -p "$(NATIVE_DIR)"
	cd "$(NATIVE_DIR)" && cmake ../..
	cd "$(NATIVE_DIR)" && make

test: native
	cd "$(NATIVE_DIR)" && make test

xcode: 
	[ -d "$(XCODE_DIR)" ] || mkdir -p "$(XCODE_DIR)"
	cd "$(XCODE_DIR)" && cmake -GXcode ../..

clean:
	$(RM) -r $(BUILD_DIR)
