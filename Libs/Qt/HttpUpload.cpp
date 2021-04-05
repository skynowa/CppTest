/**
 * \file
 * \brief
 *
 * \todo
 */


void MainWindow::on_pushButton_clicked()
{
   /**
    * --boundary
    * 1. body-part
    * --boundary
    * 2. body-part
    * --boundary
    * 3. body-part
    * --boundary--
    */

    http = new QHttp(this); // http declared as a member of MainWindow class
    connect(http, SIGNAL(requestFinished(int,bool)), SLOT(httpRequestFinished(int, bool)));

    QString boundary = "---------------------------723690991551375881941828858";

    // action
    QByteArray data(QString("--" + boundary + "\r\n").toAscii());
    data += "Content-Disposition: form-data; name=\"action\"\r\n\r\n";
    data += "file_upload\r\n";

    // file
    data += QString("--" + boundary + "\r\n").toAscii();
    data += "Content-Disposition: form-data; name=\"sfile\"; filename=\"test1.jpg\"\r\n";
    data += "Content-Type: image/jpeg\r\n\r\n";

    QFile file("/home/test1.jpg");
    if (!file.open(QIODevice::ReadOnly))
        return;

    data += file.readAll();
    data += "\r\n";

    // password
    data += QString("--" + boundary + "\r\n").toAscii();
    data += "Content-Disposition: form-data; name=\"password\"\r\n\r\n";
    //data += "password\r\n"; // put password if needed
    data += "\r\n";

    // description
    data += QString("--" + boundary + "\r\n").toAscii();
    data += "Content-Disposition: form-data; name=\"description\"\r\n\r\n";
    //data += "description\r\n"; // put description if needed
    data += "\r\n";

    // agree
    data += QString("--" + boundary + "\r\n").toAscii();
    data += "Content-Disposition: form-data; name=\"agree\"\r\n\r\n";
    data += "1\r\n";

    data += QString("--" + boundary + "--\r\n").toAscii();

    QHttpRequestHeader header("POST", "/cabinet/upload/");
    header.setValue("Host", "data.cod.ru");
    header.setValue("User-Agent", "Mozilla/5.0 (X11; U; Linux i686; en-US; rv:1.9.1.9) Gecko/20100401 Ubuntu/9.10 (karmic) Firefox/3.5.9");
    header.setValue("Accept", "text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8");
    header.setValue("Accept-Language", "en-us,en;q=0.5");
    header.setValue("Accept-Encoding", "gzip,deflate");
    header.setValue("Accept-Charset", "ISO-8859-1,utf-8;q=0.7,*;q=0.7");
    header.setValue("Keep-Alive", "300");
    header.setValue("Connection", "keep-alive");
    header.setValue("Referer", "http://data.cod.ru/");

    //multipart/form-data; boundary=---------------------------723690991551375881941828858

    header.setValue("Content-Type", "multipart/form-data; boundary=" + boundary);
    header.setValue("Content-Length", QString::number(data.length()));

    http->setHost("data.cod.ru");
    http->request(header, data);

    file.close();
}

void MainWindow::httpRequestFinished(int, bool)
{
    QHttpResponseHeader responce = http->lastResponse();
    if (responce.statusCode()==302)
    {
        qDebug() << "file accepted; get it from:";
        qDebug() << "data.cod.ru" << responce.value("Location");
    }
}
