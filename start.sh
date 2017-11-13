docker run -it -d \
-p 8181:80 -p 8122:22 -p 4075:4075 \
-v /Users/aconex/dev/:/root/workspace/ \
--name sming \
fernandopasse/sming-docker
