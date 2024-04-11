CC := g++
CFLAGS := -Wall -Wextra -std=c++11
OBJDIR := obj

# Danh sách các file nguồn
SOURCES := main.cpp System.cpp User.cpp Admin.cpp Hotel.cpp Room.cpp Travel.cpp Transport.cpp File.cpp

# Tạo danh sách các file object tương ứng với các file nguồn
OBJECTS := $(addprefix $(OBJDIR)/,$(SOURCES:.cpp=.o))

# Quy tắc biên dịch từ file nguồn sang file object
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Quy tắc biên dịch từ tất cả các file object thành chương trình thực thi
main.exe: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# Tạo thư mục chứa file object nếu nó chưa tồn tại
$(OBJDIR):
	mkdir -p $(OBJDIR)

.PHONY: clean
clean:
	rm -rf $(OBJDIR) main.exe
