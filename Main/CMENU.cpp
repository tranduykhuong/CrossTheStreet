#include"CMENU.h"

CMENU::CMENU(COORD coord, SHORT width) {
	this->coord = coord;
	this->y_ptr = coord.Y;
	this->width = width;
	this->height = 2;
	this->boxColor = BOX_COLOR;
	this->charColor = CHAR_COLOR;
}

CMENU::~CMENU() {
	this->coord = { 0,0 };
	this->y_ptr = 0;
	this->height = 0;
	this->width = 0; 
}

void CMENU::setPosition_Width(COORD coord, SHORT width) {
	this->coord = coord;
	this->y_ptr = coord.Y;
	this->width = width;
}

	//HÀM VẼ CÁC GÓC CỦA BOX Ở GIỮA (TRỪ CÁC GÓC CỦA TABLE)
void CMENU::cornerAmongBox(SHORT y_cur) {
	CONSOLE::textcolor(boxColor);
	CONSOLE::gotoXY(coord.X, y_cur);			//góc bên phải
	cout << char(195);
	CONSOLE::gotoXY(coord.X + width, y_cur);	//góc bên trái
	cout << char(180);
}

void CMENU::addItem(string ops) {
	opsArr.push_back(ops);
}

bool CMENU::removeItem(int idx) {
	if (idx >= opsArr.size() || idx < 0)
		return false;
	opsArr.erase(opsArr.begin() + idx);
	return true;
}

void CMENU::insertItem(string content, int idx) {
	opsArr.insert(opsArr.begin() + idx, content);
}

	//HÀM VẼ NỀN VÀ XUẤT TÊN CỦA OPTION 
void CMENU::dataBox(COORD coord_data, string& content, SHORT newColor) {
	short textColor = this->charColor;
	if (newColor != -1)
		textColor = newColor;

	short x_box = coord_data.X + 1;
	short y_box = coord_data.Y + 1;
	CDRAW::backroundBox(COORD{ x_box, y_box }, width - 1, height - 1, textColor);	//vẽ nền

	CONSOLE::textcolor(textColor);
	CONSOLE::gotoXY(coord_data.X + 1 + (width - content.length()) / 2, coord_data.Y + height / 2);		//đến vị trí sao cho sau khi vẽ chuỗi có thể nằm ở giữa
	cout << content;
}

void CMENU::setColorTable(SHORT boxColor, SHORT charColor) {
	this->boxColor = boxColor;
	this->charColor = charColor;
}


	//HÀM TẠO TABLE
void CMENU::displayTableLine() {
	short tempY = coord.Y;
	for (auto e : opsArr) {
		CDRAW::drawBox(COORD{ coord.X, tempY }, width, height, 196, 179, 218, 191, 192, 217, boxColor);
		dataBox(COORD{ coord.X, tempY }, e);
		if (tempY != coord.Y)
			cornerAmongBox(tempY);
		tempY += height;
	}
}

void CMENU::displayTableNoneLine() {
	short tempY = coord.Y;
	CDRAW::drawBox(COORD{ coord.X, tempY }, width, opsArr.size() +  1, 196, 179, 218, 191, 192, 217, boxColor);
	for (auto e : opsArr) {
		dataBox(COORD{ coord.X, tempY }, e);
		//tempY += height;
		tempY++;
	}
}

int CMENU::getSelectFromUser() {
	//tạo màu cho ô được chọn
	short optionColor = 64;
	int index = 0;
	int sizeOps = opsArr.size();
	
	dataBox(COORD{ coord.X, y_ptr }, opsArr[index], optionColor);		//hàm tạo màu khác cho option

	while (true) {		//sử dụng 2 phím (lên, xuống) để điều kiển
		if (_kbhit()) {		//hàm phát hiện có kí tự nhập vào
			char c = _getch();
			if (c == 13)		//khi nhập enter sẽ kết thúc while
				return index;
			else
				if (c == -32) {
					c = _getch();
					if (c == 80) {	//đi xuống
						dataBox(COORD{ coord.X, y_ptr }, opsArr[index]);			//vẽ chồng màu lên option
						if (index < sizeOps - 1) {
							y_ptr += height;
							index++;
						}
						else {
							y_ptr = coord.Y;
							index = 0;
						}
						dataBox(COORD{ coord.X, y_ptr }, opsArr[index], optionColor);		//vẽ lại option mới
					}
					else if (c == 72) { //đi lên
						dataBox(COORD{ coord.X, y_ptr }, opsArr[index]);		//vẽ chồng màu lên option
						if (index > 0) {	
							y_ptr -= height;
							index--;
						}
						else {
							y_ptr = coord.Y + (sizeOps - 1) * height;
							index = sizeOps - 1;
						}
						dataBox(COORD{ coord.X, y_ptr }, opsArr[index], optionColor);		//vẽ lại option mới
					}
				}
		}
	}
}