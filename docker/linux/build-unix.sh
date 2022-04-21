if [ "$(pwd -PW 2> /dev/null)" ]; then _pwd="pwd -PW"; else _pwd="pwd -P"; fi

self_dir="$(cd "$(dirname "$0")"; ${_pwd})"
project_root_dir=`cd ${self_dir}/../..; ${_pwd}`

image_name="feeralbee_test"


skip_docker_build=false



if ! ${skip_docker_build}; then
    docker build -t ${image_name} ${self_dir}
fi


use_terminal=-t


docker run -i ${use_terminal}  -v ${project_root_dir}:/feeralbeetest ${image_name} 

