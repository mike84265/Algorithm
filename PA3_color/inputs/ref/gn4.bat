read_graph inputs/gn4.dot
write_tree_dfs -s v0 -o outputs/ref/gn4_dfs.dot
write_tree_bfs -s v0 -o outputs/ref/gn4_bfs.dot
color_graph -m greedy -o outputs/ref/gn4_color.dot
exit
