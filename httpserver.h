#ifndef HTTPSERVER_H
#define HTTPSERVER_H

#include <QObject>
#include"Singleton.h"
#include<QNetworkAccessManager>
#include<QJsonObject>
#include<QByteArray>
#include<QJsonDocument>
#include<QNetworkReply>
#include<QUrl>
#include"const.h"
#include<QNetworkRequest>
class HttpServer:public QObject,Singleton<HttpServer>
{
    Q_OBJECT
    friend class Singleton<HttpServer>;
public:
      using Singleton<HttpServer>::getInstance;
    void post(QUrl url,QJsonObject array,Moudel id);
    ~HttpServer();
private:
    HttpServer();

    QNetworkAccessManager*manager_;
    void slot_finsh_http(Moudel id,QString res,ErrorCodes error);
signals:
    void signal_finsh_http(Moudel id,QString res,ErrorCodes error);
    void reg_finsh_http(Moudel id,QString res,ErrorCodes error);
    void forget_finsh_http(Moudel id,QString ,ErrorCodes errorres);
    void lod_finsh_http(Moudel id,QString res,ErrorCodes error);


};

#endif // HTTPSERVER_H
