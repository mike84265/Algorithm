read_graph inputs/gn4.dot
write_tree_dfs -s v0 -o outputs/mycase/gn4_dfs.dot
write_tree_bfs -s v0 -o outputs/mycase/gn4_bfs.dot
color_graph -m greedy -o outputs/mycase/gn4_color.dot
exit
