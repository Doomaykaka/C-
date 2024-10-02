.PHONY: build

CXX = g++
SOURCE_FOLDER = src
DISTRIBUTION_FOLDER = dist
TARGET = Coursework

run:
	./${DISTRIBUTION_FOLDER}/${TARGET}

build: clean
	mkdir -p ${DISTRIBUTION_FOLDER}
	$(CXX) -o ${DISTRIBUTION_FOLDER}/${TARGET} ${SOURCE_FOLDER}/*.cpp

clean:
	rm -rf ${DISTRIBUTION_FOLDER}/
