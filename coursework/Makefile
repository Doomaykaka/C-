.PHONY: build

CXX = g++
SOURCE_FOLDER = src
DISTRIBUTION_FOLDER = dist
TARGET = Coursework

run:
	./${DISTRIBUTION_FOLDER}/${TARGET}

debug:
	gdb ./${DISTRIBUTION_FOLDER}/${TARGET}

build: build_release

build_release: build_folder
	$(CXX) -o ${DISTRIBUTION_FOLDER}/${TARGET} ${SOURCE_FOLDER}/*.cpp

build_debug: build_folder
	$(CXX) -o ${DISTRIBUTION_FOLDER}/${TARGET} -g ${SOURCE_FOLDER}/*.cpp

build_folder: clean
	mkdir ${DISTRIBUTION_FOLDER}

clean:
	rm -rf ${DISTRIBUTION_FOLDER}/
