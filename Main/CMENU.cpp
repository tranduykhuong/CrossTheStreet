#include"CMENU.h"

CMENU::CMENU(int x, int y, int width) {
	this->x = x;
	this->y = y;
	this->y_ptr = y;
	this->width = width;
	this->height = 2;
	this->boxColor = BOX_COLOR;
	this->charColor = CHAR_COLOR;
}

CMENU::~CMENU() {
	this->x = 0;
	this->y = 0;
	this->y_ptr = 0;
	this->height = 0;
	this->width = 0; 
}

void CMENU::setPosition_Width(int x, int y, int width) {
	this->x = x;
	this->y = y;
	this->y_ptr = y;
	this->width = width;
}

	//HÀM VẼ CÁC GÓC CỦA BOX Ở GIỮA (TRỪ CÁC GÓC CỦA TABLE)
void CMENU::cornerAmongBox(int y_cur) {
	textcolor(boxColor);
	gotoXY(x, y_cur);			//góc bên phải
	cout << char(195);
	gotoXY(x + width, y_cur);	//góc bên trái
	cout << char(180);
}

void CMENU::addOption(string ops) {
	opsArr.push_back(ops);
}

	//HÀM VẼ NỀN VÀ XUẤT TÊN CỦA OPTION 
void CMENU::dataBox(int x_data, int y_data, string& content, int newColor) {
	int textColor = this->charColor;
	if (newColor != -1)
		textColor = newColor;
	draw.backroundBox(x_data + 1, y_data + 1, width - 1, height - 1, textColor);	//vẽ nền

	textcolor(textColor);
	gotoXY(x_data + 1 + (width - content.length()) / 2, y_data + height / 2);		//đến vị trí sao cho sau khi vẽ chuỗi có thể nằm ở giữa
	cout << content;
}

void CMENU::setColorBox(int boxColor, int charColor) {
	this->boxColor = boxColor;
	this->charColor = charColor;
}


	//HÀM TẠO TABLE
void CMENU::displayTable() {
	int tempY = y;
	for (auto e : opsArr) {
		draw.drawBox(x, tempY, width, height, 196, 179, 218, 191, 192, 217, boxColor);
		dataBox(x, tempY, e);
		if (tempY != y)
			cornerAmongBox(tempY);
		tempY += height;
	}
}

int CMENU::getSelectFromUser() {
	//tạo màu cho ô được chọn
	int optionColor = 64;
	int index = 0;
	int sizeOps = opsArr.size();
	
	dataBox(x, y_ptr, opsArr[index], optionColor);		//hàm tạo màu khác cho option

	while (true) {		//sử dụng 2 phím (lên, xuống) để điều kiển
		if (_kbhit()) {		//hàm phát hiện có kí tự nhập vào
			char c = _getch();
			if (c == 13)		//khi nhập enter sẽ kết thúc while
				return index;
			else
				if (c == -32) {
					c = _getch();
					if (c == 80) {	//đi xuống
						dataBox(x, y_ptr, opsArr[index]);			//vẽ chồng màu lên option
						if (index < sizeOps - 1) {
							y_ptr += height;
							index++;
						}
						else {
							y_ptr = y;
							index = 0;
						}
						dataBox(x, y_ptr, opsArr[index], optionColor);		//vẽ lại option mới
					}
					else if (c == 72) { //đi lên
						dataBox(x, y_ptr, opsArr[index]);		//vẽ chồng màu lên option
						if (index > 0) {	
							y_ptr -= height;
							index--;
						}
						else {
							y_ptr = y + (sizeOps - 1) * height;
							index = sizeOps - 1;
						}
						dataBox(x, y_ptr, opsArr[index], optionColor);		//vẽ lại option mới
					}
				}
		}
	}
}