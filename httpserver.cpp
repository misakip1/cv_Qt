#include "httpserver.h"


void HttpServer::post(QUrl url, QJsonObject json_,Moudel id)
{
    if(url.isEmpty())
        return;

    QByteArray array=QJsonDocument(json_).toJson();
    reply_=manager_->post(QNetworkRequest(url),array);
    connect(reply_,&QNetworkReply::finished,[this,id](){
        if(this->reply_->error()!=QNetworkReply::NoError)
            {
            qDebug()<<"网络收包失败";
            emit signal_finsh_http(id,"",ErrorCodes::ERR_NETWORK);
            reply_->deleteLater();
            }
        else
            {
            QString res=this->reply_->readAll();
            emit signal_finsh_http(id,res,ErrorCodes::SUCCESS);
            reply_->deleteLater();
            }
    });


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
    else
    {
        emit reg_finsh_http(id,res,error);
    }
}


