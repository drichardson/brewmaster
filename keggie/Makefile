BUILD_DIR=build
NATIVE_DIR=$(BUILD_DIR)/native

native: 
	[ -d "$(NATIVE_DIR)" ] || mkdir -p "$(NATIVE_DIR)"
	cd "$(NATIVE_DIR)" && cmake ../..
	cd "$(NATIVE_DIR)" && make

clean:
	$(RM) -r $(BUILD_DIR)
