# 地图介绍

该文件夹存放自定义闯关地图

## 添加地图方式

* 通过项目内函数往其中添加txt文件生成地图（Map类中的GenerateMap()函数）

* 直接在此文件夹中写txt文件

  

## 规范

txt文件内每一行即为每一块墙的坐标，以逗号为分隔符，换行为墙之间的区别符号，如

```txt
2,2
4,4
6,6
8,8
```

请将x设计成__偶数__，以保证地图加载正确

x的范围为[0, 2 * COL]，y的范围为[0, 2 * ROW]

文件命名请符合 __map+ 地图编号 + .txt__ 格式，并使用Map类的LoadMap()函数加载对应地图