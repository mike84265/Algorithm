read_graph inputs/gn10000.dot
write_tree_dfs -s v0 -o outputs/ref/gn10000_dfs.dot
write_tree_bfs -s v0 -o outputs/ref/gn10000_bfs.dot
color_graph -m greedy -o outputs/ref/gn10000_color.dot
exit
