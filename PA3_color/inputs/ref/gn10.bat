read_graph inputs/gn10.dot
write_tree_dfs -s v0 -o outputs/ref/gn10_dfs.dot
write_tree_bfs -s v0 -o outputs/ref/gn10_bfs.dot
color_graph -m greedy -o outputs/ref/gn10_color.dot
exit
