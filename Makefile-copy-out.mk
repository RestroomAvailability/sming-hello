SHARED_PROJECT_BINARIES_DIRECTORY = ~/workspace/$(notdir $(CURDIR))/binaries

copy_output:
	echo "Copying build output to $(SHARED_PROJECT_OUTPUT_DIRECTORY)"
	rm -rf $(SHARED_PROJECT_BINARIES_DIRECTORY)
	mkdir -p $(SHARED_PROJECT_BINARIES_DIRECTORY)
	cp -r out/firmware/* $(SHARED_PROJECT_BINARIES_DIRECTORY)
