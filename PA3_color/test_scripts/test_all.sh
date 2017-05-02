#!/usr/bin/env bash
bin/graphlab -f inputs/mycase/gn4.dot
ref/graphlab_ref -f inputs/ref/gn4.dot
bin/graphlab -f inputs/mycase/gn8.dot
ref/graphlab_ref -f inputs/ref/gn8.dot
bin/graphlab -f inputs/mycase/gn10.dot
ref/graphlab_ref -f inputs/ref/gn10.dot
bin/graphlab -f inputs/mycase/gn100.dot
ref/graphlab_ref -f inputs/ref/gn100.dot
bin/graphlab -f inputs/mycase/gn1000.dot
ref/graphlab_ref -f inputs/ref/gn1000.dot
bin/graphlab -f inputs/mycase/gn10000.dot
ref/graphlab_ref -f inputs/ref/gn10000.dot
