#include "httpserver.h"


void HttpServer::post(QUrl url, QJsonObject json_,Moudel id)
{
    if(url.isEmpty())
        return;

    QByteArray array=QJsonDocument(json_).toJson();
    QNetworkRequest req_;
    req_.setRawHeader("Content-Type", "application/json");
    req_.setRawHeader("Connection", "close");
    req_.setUrl(url);
    QNetworkReply* reply_ = manager_->post(req_, array);
    // 不要捕获reply_！在回调里面用sender()拿到
    connect(reply_, &QNetworkReply::finished, this, [this, id](){
        QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
        if (!reply)
        {
            qDebug() << "reply为空";
            emit signal_finsh_http(id, "", ErrorCodes::ERR_NETWORK);
            return;
        }
        if(reply->error() != QNetworkReply::NoError)
        {
            QByteArray data = reply->readAll();

            qDebug() << "网络收包失败:" << reply->errorString();
            qDebug() << "服务端返回:" << data;
            emit signal_finsh_http(id,"",ErrorCodes::ERR_NETWORK);
        }
        else
        {
            QString res=reply->readAll();
            qDebug() << "收到服务端返回原始内容：" << res;
            emit signal_finsh_http(id,res,ErrorCodes::SUCCESS);
        }
        reply->deleteLater();
    }, Qt::QueuedConnection);


}

HttpServer::~HttpServer()
{

}

HttpServer::HttpServer()
{
    manager_=new QNetworkAccessManager(this);
    connect(this,&HttpServer::signal_finsh_http,this,&HttpServer::slot_finsh_http);

}

void HttpServer::slot_finsh_http(Moudel id, QString res, ErrorCodes error)
{
    if(id==Moudel::ForgetModel)
    {
        emit forget_finsh_http(id,res,error);
    }
    else if(id==Moudel::LodingModel)
    {
        emit lod_finsh_http(id,res,error);
    }
    else if(id==Moudel::RegModel)
    {
        emit reg_finsh_http(id,res,error);
    }
}


