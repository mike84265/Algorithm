read_graph inputs/gn8.dot
write_tree_dfs -s v0 -o outputs/ref/gn8_dfs.dot
write_tree_bfs -s v0 -o outputs/ref/gn8_bfs.dot
color_graph -m greedy -o outputs/ref/gn8_color.dot
exit
