
name=jakobleben/arrp-web-engine
verion=$(cat ../VERSION)

docker build -t $name:$version .
