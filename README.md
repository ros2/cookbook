# cookbook

## installing your cookbook
(subject to change)

```
mkdir -p ~/ros2/src
cd ~/ros2
wget https://raw.githubusercontent.com/ros2/ros2/master/ros2.repos
vcs import src < ros2.repos
cd ~/ros2/src
git clone ssh://git@github.com/ros2/cookbook -o cookbook
```

## building your cookbook
```
cd ~/ros2
src/ament/ament_tools/scripts/ament.py build -s
```
