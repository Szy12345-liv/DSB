dataset/turn.cpp将一张图加上颜色和比例要求

dataset/validator.cpp检测图的合法性 (是否有重边，自环，点编号是否超出n)

plant/gen.cpp生成植入答案的图

dataset/intro.txt 写了数据来源

dataset/graph1~4太大了 传不上去

graph的格式是n m '\n' {u,v}，其中n和m代表图的节点数和边数，{u,v}代表边，节点1-index

input的格式是n m rmn rmx k '\n' c1,c2...cn '\n' {u,v}，其中rmn,rmx代表比例不超过\frac{rmx}{rmn}，ci代表颜色

program/gen.cpp 生成一些小数据

program/br.cpp 2^n暴力

program/exact.cpp 搜索剪枝，大概能跑30+