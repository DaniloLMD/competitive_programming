NAME = word

all:
	make $(NAME) && ./$(NAME)
	rm ./$(NAME)

gen:
	cp ../template/template.cpp $(NAME).cpp
	code $(NAME).cpp

count:
	make COUNT
	./COUNT
	rm COUNT