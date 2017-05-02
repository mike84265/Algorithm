// **************************************************************************
// File       [ test_cmd.cpp ]
// Author     [ littleshamoo ]
// Synopsis   [ ]
// Date       [ 2012/04/10 created ]
// **************************************************************************

#include "user_cmd.h"
#include "graph.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <queue>
#include "../lib/tm_usage.h"
using namespace std;
using namespace CommonNs;
void DFStree(Node* s, ofstream& ofs, int& v, int& e);

extern Graph graph;

TestCmd::TestCmd(const char * const name) : Cmd(name) {
    optMgr_.setShortDes("test");
    optMgr_.setDes("test");

    Opt *opt = new Opt(Opt::BOOL, "print usage", "");
    opt->addFlag("h");
    opt->addFlag("help");
    optMgr_.regOpt(opt);

    opt = new Opt(Opt::STR_REQ, "print the string of -s", "[string]");
    opt->addFlag("s");
    optMgr_.regOpt(opt);
}

TestCmd::~TestCmd() {}

bool TestCmd::exec(int argc, char **argv) {
    optMgr_.parse(argc, argv);

    if (optMgr_.getParsedOpt("h")) {
        optMgr_.usage();
        return true;
    }

    if (optMgr_.getParsedOpt("s")) {
        printf("%s\n", optMgr_.getParsedValue("s"));
    }
    else
        printf("hello world !!\n");


    return true;
}

ReadCmd::ReadCmd(const char* const name) : Cmd(name) {
    optMgr_.setShortDes("read the graph");
    optMgr_.setDes("read the graph from a dot file");

    Opt *opt = new Opt(Opt::BOOL, "print usage", "");
    opt->addFlag("h");
    opt->addFlag("help");
    optMgr_.regOpt(opt);

    opt = new Opt(Opt::STR_REQ, "read the dot file", "<file>");
    optMgr_.regOpt(opt);
}

ReadCmd::~ReadCmd() {}

bool ReadCmd::exec(int argc, char **argv) {
   optMgr_.parse(argc, argv);

   if (optMgr_.getParsedOpt("h")) {
      optMgr_.usage();
      return true;
   }

   if (argc != 2) {
      fprintf(stderr, "**ERROR ReadCmd::exec(): ");
      fprintf(stderr, "please specify input graph file\n");
      return false;
   }
   
   ifstream ifs(argv[1]);
   string str;
   int f, v1, v2, w;
   while (!ifs.eof()) {
      getline(ifs, str);
      size_t n = str.find_first_not_of(' ');
      if (n != string::npos)
         str = str.substr(n);
      f = sscanf(str.c_str(),"v%d -- v%d [label = \"%d\"];", &v1, &v2, &w);
      if (f != 0)
         graph.addEdge(v1, v2, w);
   }
   ifs.close();
   return true;
}

DFSCmd::DFSCmd(const char * const name) : Cmd(name) {
   optMgr_.setShortDes("write_tree_dfs");
   optMgr_.setDes("write_tree_dfs");

   Opt *opt = new Opt(Opt::BOOL, "print usage", "");
   opt->addFlag("h");
   opt->addFlag("help");
   optMgr_.regOpt(opt);

   opt = new Opt(Opt::STR_REQ, "print the string of -s", "<source_node>, <dot_filename>");
   opt->addFlag("s");
   opt->addFlag("o");
   optMgr_.regOpt(opt);
}

DFSCmd::~DFSCmd() {}

bool DFSCmd::exec(int argc, char** argv) {
   optMgr_.parse(argc, argv);

   if (optMgr_.getParsedOpt("h")) {
      optMgr_.usage();
      return true;
   }

   if (argc != 5) {
      fprintf(stderr, "**ERROR DFSCmd::exec(): ");
      return false;
   }
      
   int s = atoi(argv[2]);
   TmUsage tmusg;
   TmStat stat;
   ofstream ofs(argv[4]);
   ofs << "// DFS tree produced by graphlab" << endl;
   ofs << "graph " << graph.name << "_dfs {" << endl;

   tmusg.periodStart();
   graph.init();
   Node* source = graph.getNodeById(s);
   int e=0, v=1;
   DFStree(source, ofs, v, e);

   tmusg.getPeriodUsage(stat);
   ofs << "}" << endl;
   ofs << "// vertices = " << v << endl;
   ofs << "// edges = " << e << endl;
   ofs << "// runtime = " << (stat.uTime + stat.sTime) / 1000000.0 << " sec" << endl;
   ofs << "// memory = " << stat.vmPeak/1000.0 << " MB" << endl;
   ofs.close();
   return true;
}

void DFStree(Node* s, ofstream& ofs, int& v, int& e) {
   s->traveled = true;
   s->sortEdge();
   size_t n = s->edge.size();
   for (size_t i=0;i<n;++i) {
      Node* next_node = s->edge[i]->getNeighbor(s);
      if (!next_node->traveled) {
         ++v; ++e;
         ofs << "v" << s->id << " -- v" << next_node->id << ";" << endl;
         DFStree(next_node,ofs,v,e);
      }
   }
}

BFSCmd::BFSCmd(const char * const name) : Cmd(name) {
   optMgr_.setShortDes("write_tree_bfs");
   optMgr_.setDes("write_tree_bfs");

   Opt *opt = new Opt(Opt::BOOL, "print usage", "");
   opt->addFlag("h");
   opt->addFlag("help");
   optMgr_.regOpt(opt);

   opt = new Opt(Opt::STR_REQ, "Perform BFS starting from source node. Then write to a dot file.",
      "<source_node>, <dot_filename>");
   opt->addFlag("s");
   opt->addFlag("o");
   optMgr_.regOpt(opt);
}

BFSCmd::~BFSCmd() {}

bool BFSCmd::exec(int argc, char** argv) {
   optMgr_.parse(argc, argv);

   if (optMgr_.getParsedOpt("h")) {
      optMgr_.usage();
      return true;
   }

   if (argc != 5) {
      fprintf(stderr, "**ERROR BFSCmd::exec(): ");
      return false;
   }
      
   int s = atoi(argv[2]);
   TmUsage tmusg;
   TmStat stat;
   ofstream ofs(argv[4]);
   ofs << "// BFS tree produced by graphlab" << endl;
   ofs << "graph " << graph.name << "_dfs {" << endl;

   tmusg.periodStart();
   graph.init();
   Node* source = graph.getNodeById(s);
   int e=0, v=1;
   queue<Node*> nodeQueue;
   nodeQueue.push(source);
   while (!nodeQueue.empty()) {
      Node* current_node = nodeQueue.front();
      if (current_node->color != 1) {
         current_node->color = 1;
         current_node->sortEdge();
         size_t n = current_node->edge.size();
         for (size_t i=0;i<n;++i) {
            Node* next_node = current_node->edge[i]->getNeighbor(current_node);
            if (next_node->color == -1) {
               ++v; ++e;
               next_node->color = 0;
               nodeQueue.push(next_node);
               ofs << "v" << current_node->id << " -- v" << next_node->id << ";" << endl;
            }
         }
      }
      nodeQueue.pop();
   }
   graph.init();

   tmusg.getPeriodUsage(stat);
   ofs << "}" << endl;
   ofs << "// vertices = " << v << endl;
   ofs << "// edges = " << e << endl;
   ofs << "// runtime = " << (stat.uTime + stat.sTime) / 1000000.0 << " sec" << endl;
   ofs << "// memory = " << stat.vmPeak/1000.0 << " MB" << endl;
   ofs.close();
   return true;
}

ColorCmd::ColorCmd(const char * const name) : Cmd(name) {
   optMgr_.setShortDes("color the tree");
   optMgr_.setDes("color up the tree");

   Opt *opt = new Opt(Opt::BOOL, "print usage", "");
   opt->addFlag("h");
   opt->addFlag("help");
   optMgr_.regOpt(opt);

   opt = new Opt(Opt::STR_REQ, "Color the tree", "<algorithm>, <dot_filename>");
   opt->addFlag("m");
   opt->addFlag("o");
   optMgr_.regOpt(opt);
}

ColorCmd::~ColorCmd() {}

bool ColorCmd::exec(int argc, char** argv) {
   optMgr_.parse(argc, argv);

   if (optMgr_.getParsedOpt("h")) {
      optMgr_.usage();
      return true;
   }

   if (argc != 5) {
      fprintf(stderr, "**ERROR ColorCmd::exec(): ");
      return false;
   }
      
   int s = atoi(argv[2]);
   TmUsage tmusg;
   TmStat stat;
   ofstream ofs(argv[4]);
   ofs << "// BFS tree produced by graphlab" << endl;
   ofs << "graph " << graph.name << "_dfs {" << endl;

   int colors = 0;
   graph.sortNodesByDegree();
   graph.sortEdgesOfNode();
   size_t n = graph.nodes.size();
   for (size_t i=0;i<n;++i) {
      int c = 1;
      Node* current_node = graph.nodes[i];
      vector<Edge*>& checkList = current_node->edge;
      size_t m = checkList.size();
      while (1) {
         int temp = c;
         for (size_t j=0;j<m;++j) {
            if (c == checkList[j]->getNeighbor(current_node)->color)
               ++c;
         }
         if (temp == c)
            break;
      }
      current_node->color = c;
      if (c > colors)
         colors = c;
   }

   graph.sortNodesByID();
   for (size_t i=0;i<n;++i) {
      Node* node = graph.nodes[i];
      ofs << "v" << node->id << " [label = \"v" << node->id << "_color"
          << node->color << "\"];" << endl;
   }

   tmusg.getPeriodUsage(stat);
   ofs << "}" << endl;
   ofs << "// vertices = " << graph.nodes.size() << endl;
   ofs << "// edges = " << graph.edges.size() << endl;
   ofs << "// number_of_colors = " << colors << endl;
   ofs << "// runtime = " << (stat.uTime + stat.sTime)/1000000.0 << " sec" << endl;
   ofs << "// memory = " << stat.vmPeak/1000.0 << " MB" << endl;
   ofs.close();

   return true;

}
