#!/bin/bash

cd ../../
docker rmi -f ereva/valgrind/viewer
docker build . -t ereva/valgrind/viewer -f src/Valgrind/Dockerfile
docker run --rm ereva/valgrind/viewer

