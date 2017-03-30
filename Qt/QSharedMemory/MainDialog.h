/**
 * \file  MainDialog.cpp
 * \brief

 * Well, I hope you can do something with my messy example. I didn't consider waiting for threads
 * termination, memory freeing and server separated thread for sending messages (in case client
 * reads data too long time), just the main problem: waiting for shared memory without active
 * pooling.
 *
 * You need to run two processes (the same executable), they will configure themselves.
 * The first one sends message on button clicked event, and the second one waits, receives and
 * shows text in QLabel. You can use QSharedMemory lock/unlock or QSystemSemaphore interchangeably,
 * see comments in cpp. You need to use uic/moc and build ui by yourself,
 * ther is only QLineEdit (whatToSend), QPushButton and QLabel (whatReceived).
 */


#pragma once

#include "dialog.h"

#include <QtWidgets\qdialog.h>
#include <QtCore\qsharedmemory.h>
#include <QtCore\qthread.h>
#include <QtCore\qsystemsemaphore.h>
//-------------------------------------------------------------------------------------------------
class MainDialog :
	public QDialog,
	public Ui::Dialog
{
	Q_OBJECT

public:
		 MainDialog();
		~MainDialog();

public Q_SLOTS:
	void onTextReady(QString text);
	void onSend();

private:
	QSharedMemory    _sharedMemory;
	QSystemSemaphore _sysSemaphoreWriteDone;
};
//-------------------------------------------------------------------------------------------------
class ThreadClient :
	public QThread
{
	Q_OBJECT

public:
			ThreadClient(QSharedMemory &sharedMemory);
	void 	run();

Q_SIGNALS:
	void 	sig_textReady(QString);

private:
	QSystemSemaphore  _sysSemaphoreWriteDone;
	QSharedMemory    &_sharedMemory;
};
//-------------------------------------------------------------------------------------------------
