# cookbook

Welcome!
This repo contains some short-and-sweet recipes for doing a variety of tasks in
ROS 2.
The hope is that some of this code will be useful to copy-and-paste as you are
working on your own projects.
Cheers!

## installing your cookbook
(subject to change)

```
mkdir -p ~/ros2/src
cd ~/ros2
wget https://raw.githubusercontent.com/ros2/ros2/master/ros2.repos
vcs import src < ros2.repos
cd ~/ros2/src
git clone https://github.com/ros2/cookbook -o cookbook
```

## building your cookbook
```
cd ~/ros2
src/ament/ament_tools/scripts/ament.py build -s
```

## License

All software in this cookbook is released under the Apache 2.0 License, as
provided in the LICENSE file in the root of this repository.
