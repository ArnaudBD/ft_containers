NAME = CONTAINERS
SRCS = main.cpp

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
OBJDIR = obj

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
FT = -D NAMESPACE=ft
STL = -D NAMESPACE=std

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -D NAMESPACE=$(n) -c $< -o $@
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -D NAMESPACE=$n $(OBJS) -o $(NAME)

debug: CFLAGS += -g -fsanitize=address -fno-omit-frame-pointer
debug: re

tester:
	$(MAKE) fclean
	@echo "FT" > ft.txt
	$(MAKE) n=ft > build_ft.txt
	./$(NAME) >> ft.txt
	$(MAKE) fclean --silent
	@echo "STD" > std.txt
	$(MAKE) n=std > build_std.txt
	./$(NAME) >> std.txt
	@echo "Differences:"
	@diff ft.txt std.txt
	@echo "Done"

#tester:
#	$(MAKE) all > build.log  # Compile the "all" target with silent output, save the output in build.log
#	./$(NAME) > ft.txt  # Run the compiled program and redirect its output to ft.txt
#	$(MAKE) clean > clean.log  # Clean up the compiled files, save the output in clean.log
#	$(MAKE) STL='-D NAMESPACE=std' > build_std.log  # Compile the "all" target with a different preprocessor define, save the output in build_std.log
#	./$(NAME) > std.txt  # Run the compiled program and redirect its output to std.txt
#	@echo "Differences:"
#	@diff ft.txt std.txt  # Compare the two output files
#	@diff -u ft.txt std.txt > diff.txt  # Save the differences in a separate file
#	@echo "Done"

all: $(NAME)


clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
