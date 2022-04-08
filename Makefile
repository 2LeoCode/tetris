BUILD=	build
SRC=	src

all: $(BUILD)/Makefile
	make -C$(BUILD)

$(BUILD)/Makefile:
	cmake -B$(BUILD)

clean:
	make $@ -C$(BUILD)

fclean:
	rm -rf $(BUILD)

re: fclean all

.PHONY: all clean fclean re
