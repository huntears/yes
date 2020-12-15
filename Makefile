include config.mk

all: $(OBJ)
	$(CC) -o $(TARGET) $(OBJ) $(LFLAGS)

%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(TARGET)

re: fclean all
