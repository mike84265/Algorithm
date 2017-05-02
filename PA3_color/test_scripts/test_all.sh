#!/usr/bin/env bash
v[0]='4'
v[1]='8'
v[2]='10'
v[3]='100'
v[4]='1000'
v[5]='10000'

rm mydata
rm refdata
for i in $(seq 0 5); do
echo "gn${v[$i]}.bat"
bin/graphlab -f inputs/mycase/gn${v[$i]}.bat >> mydata
ref/graphlab_ref -f inputs/ref/gn${v[$i]}.bat >> refdata
done

for i in $(seq 0 5); do
echo "comparing gn4..."
diff outputs/mycase/gn${v[$i]}_dfs.dot outputs/ref/gn${v[$i]}_dfs.dot 
diff outputs/mycase/gn${v[$i]}_bfs.dot outputs/ref/gn${v[$i]}_bfs.dot 
diff outputs/mycase/gn${v[$i]}_color.dot outputs/ref/gn${v[$i]}_color.dot 
done
