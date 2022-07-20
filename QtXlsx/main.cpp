#include <QtCore/QCoreApplication>
#include "QtXlsx/QtXlsx"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
	QXlsx::Document xlsx;
	QXlsx::Format headStyle;
	xlsx.setColumnWidth(1, 2, 40);
	headStyle.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
	headStyle.setVerticalAlignment(QXlsx::Format::AlignVCenter);
	QFont headFont;
	headFont.setPointSize(14);
	headFont.setBold(true);
	headFont.setFamily("Microsoft YaHei");
	headStyle.setFont(headFont);
	xlsx.write(1, 1, u8"时间", headStyle);
	xlsx.write(1, 2, u8"地点", headStyle);
	QXlsx::Format contextStyle;
	contextStyle.setHorizontalAlignment(QXlsx::Format::AlignLeft);
	contextStyle.setVerticalAlignment(QXlsx::Format::AlignTop);
	contextStyle.setFontSize(12);
	contextStyle.setFontName("Microsoft YaHei");
	int index = 2;
	for (int i = 0; i < 5; i++)
	{
		xlsx.write(index, 1, QString(u8"时间%1").arg(QString::number(i)), contextStyle);
		xlsx.write(index, 2, QString(u8"地点%1").arg(QString::number(i)), contextStyle);
		index++;
	}
	xlsx.saveAs(QCoreApplication::applicationDirPath()+"/examle.xlsx");
    return a.exec();
}
