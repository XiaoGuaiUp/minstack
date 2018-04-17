minstack:minstack.c seqstack.c
	gcc $^ -o $@

.PHONY:clean
	clean:
		rm -f minstack
