#!/bin/bash

ls alias_test/*.sql
for i in `ls alias_test/*.sql`
#for i in `ls test/test_*.sql`
do 
	echo "-------------$i-------------------"
	cat $i
	echo ""

	./sqlprov $i
	echo ""
	echo ""
done 
