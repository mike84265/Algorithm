#!/usr/bin/env bash
echo "read_graph inputs/gn$1.dot" > "inputs/$2/gn$1.bat"
echo "write_tree_dfs -s v0 -o outputs/$2/gn$1_dfs.dot" >> "inputs/$2/gn$1.bat"
echo "write_tree_bfs -s v0 -o outputs/$2/gn$1_bfs.dot" >> "inputs/$2/gn$1.bat"
echo "color_graph -m greedy -o outputs/$2/gn$1_color.dot" >> "inputs/$2/gn$1.bat"
echo "exit" >> "inputs/$2/gn$1.bat"
