/**
 * \file
 * \brief
 *
 * \todo
 */


#include "MainDialog.h"

#include <QtWidgets\qapplication.h>

//-------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{
	QApplication app(argc, argv);

	MainDialog dlg;
	dlg.show();

	return app.exec();
}
//-------------------------------------------------------------------------------------------------
