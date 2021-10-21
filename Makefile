NAME = libft.a

HEADER = libft.h

PT1_DIR = ./mandatory_pt1/

PT2_DIR = ./mandatory_pt2/

BNS_DIR = ./bonus_part/

LIST =	${PT1_DIR}ft_atoi.c ${PT1_DIR}ft_bzero.c ${PT1_DIR}ft_calloc.c\
		${PT1_DIR}ft_isalpha.c ${PT1_DIR}ft_isalnum.c ${PT1_DIR}ft_isascii.c\
		${PT1_DIR}ft_isdigit.c ${PT1_DIR}ft_isprint.c ${PT2_DIR}ft_itoa.c\
		${PT1_DIR}ft_memchr.c ${PT1_DIR}ft_memcmp.c ${PT1_DIR}ft_memcpy.c\
		${PT1_DIR}ft_memmove.c ${PT1_DIR}ft_memset.c ${PT2_DIR}ft_putchar_fd.c\
		${PT2_DIR}ft_putendl_fd.c ${PT2_DIR}ft_putnbr_fd.c ${PT2_DIR}ft_putstr_fd.c\
		${PT2_DIR}ft_split.c ${PT1_DIR}ft_strchr.c ${PT1_DIR}ft_strdup.c ${PT1_DIR}ft_toupper.c\
		${PT2_DIR}ft_striteri.c ${PT2_DIR}ft_strjoin.c ${PT1_DIR}ft_strlcat.c\
		${PT1_DIR}ft_strlcpy.c ${PT1_DIR}ft_strlen.c ${PT2_DIR}ft_strmapi.c\
		${PT1_DIR}ft_strncmp.c ${PT1_DIR}ft_strnstr.c ${PT1_DIR}ft_strrchr.c\
		${PT2_DIR}ft_strtrim.c ${PT2_DIR}ft_substr.c ${PT1_DIR}ft_tolower.c

LIST_B = ${BNS_DIR}ft_lstnew.c ${BNS_DIR}ft_lstadd_front.c ${BNS_DIR}ft_lstsize.c\
			${BNS_DIR}ft_lstdelone.c ${BNS_DIR}ft_lstadd_back.c ${BNS_DIR}ft_lstlast.c\
			${BNS_DIR}ft_lstclear.c ${BNS_DIR}ft_lstiter.c ${BNS_DIR}ft_lstmap.c 

OBJ = ${patsubst %.c, %.o, ${LIST}}

OBJ_B = ${patsubst %.c, %.o, ${LIST_B}}

FLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
	ar rcs ${NAME} $?

%.o : %.c ${HEADER}
	gcc ${FLAGS} -c $< -o $@

bonus : 
	make OBJ="${OBJ_B}" all

clean :
	rm -f ${OBJ} ${OBJ_B}

fclean : clean
	rm -f ${NAME}

re : fclean all

.PHONY : all clean fclean re bonus