/**
 * \file  MainDialog.cpp
 * \brief
 */


#include "MainDialog.h"

#include <QtCore\qtextstream.h>
#include "MainDialog.moc"


/**************************************************************************************************
*   MainDialog
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
MainDialog::MainDialog() :
	_sharedMemory         ("SharedMemory"),
	_sysSemaphoreWriteDone("SysSemaphoreWriteDone", 0)
{
	setupUi(this);

	bool result = _sharedMemory.create(1024);
	if (result) {
		// We've created memory, so we are first. This one will send messages.
		char *to = (char *)_sharedMemory.data();
		memset(to, 0, _sharedMemory.size());

		connect(m_sendButton, SIGNAL(clicked()), this, SLOT(onSend()));
	} else {
		// Shared memory already exists, so this is second process. This one will listen.
		result = _sharedMemory.attach();
		Q_ASSERT(result);

		m_sendButton->setEnabled(false);

		ThreadClient *client = new ThreadClient(_sharedMemory);
		connect(client, SIGNAL( sig_textReady(QString) ), this, SLOT( onTextReady(QString) ));

		client->start();
	}
}
//-------------------------------------------------------------------------------------------------
MainDialog::~MainDialog()
{
	// need to add waiting for thread termination
}
//-------------------------------------------------------------------------------------------------
void
MainDialog::onTextReady(
	QString a_text
)
{
	m_receivedTextLabel->setText(a_text);
}
//-------------------------------------------------------------------------------------------------
void
MainDialog::onSend()
{
	//-- _sharedMemory.lock();
	char *to = (char *)_sharedMemory.data();

	QString  text = m_whatToSend->text();
	QChar   *data = text.data();

	while ( !data->isNull() ) {
		memset( to, data->toLatin1(), 1 );
		++ data;
		++ to;
	}

	memset(to, 0, 1); // null terminator
	//-- _sharedMemory.unlock();
	//-- _sharedMemory.lock();

	// resume other process
	_sysSemaphoreWriteDone.release();

	// this one will block client again, however, it could take time for client to read data,
	_sysSemaphoreWriteDone.acquire();
}
//-------------------------------------------------------------------------------------------------


/**************************************************************************************************
*   ThreadClient
*
**************************************************************************************************/

//-------------------------------------------------------------------------------------------------
// you can comment semaphores and uncomment lock/unlock, result will be the same
ThreadClient::ThreadClient(
	QSharedMemory &a_sharedMemory
) :
	// I assume that counter is already initialized by the server
	_sysSemaphoreWriteDone("SysSemaphoreWriteDone"),
	_sharedMemory         (a_sharedMemory)
{
}
//-------------------------------------------------------------------------------------------------
void
ThreadClient::run()
{
	while (true) {
		// there is no active pooling, we just wait for semaphore
		_sysSemaphoreWriteDone.acquire();

		//-- _sharedMemory.lock();
		char const *from = (char const *)_sharedMemory.data();

		QString     text;
		QTextStream stream(&text);

		while (from && *from) {
			stream << *from;
			++ from;
		}

		//-- _sharedMemory.unlock();
		_sysSemaphoreWriteDone.release();

		Q_EMIT sig_textReady(text);
	}
}
//-------------------------------------------------------------------------------------------------
