read_graph inputs/gn1000.dot
write_tree_dfs -s v0 -o outputs/ref/gn1000_dfs.dot
write_tree_bfs -s v0 -o outputs/ref/gn1000_bfs.dot
color_graph -m greedy -o outputs/ref/gn1000_color.dot
exit
