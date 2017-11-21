docker rm -f sming 2>/dev/null

docker run -it -d \
-p 8181:80 -p 8122:22 -p 4075:4075 \
-v $(dirname "$PWD"):/root/workspace/ \
--name sming \
fernandopasse/sming-docker