#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include "simplecrypt.h"
#include <QDir>
#include <QDebug>
int main(int argc, char *argv[])
{
    QString nombre,nombre_cifrado;
    QString clave,clave_cifrado;
    QString servicio = "";
    servicio = qgetenv("PAM_SERVICE");
    if (servicio == "sddm"){
        QTextStream qtin(stdin);
        clave = qtin.readLine();
        clave.chop(1);
        nombre = qgetenv("PAM_USER");
        QString fichero="/home/"+nombre+"/.grx/.proxy";
        if (!QDir("/home/"+nombre+"/.grx").exists()){
            QDir().mkdir("/home/"+nombre+"/.grx");
        }
        SimpleCrypt *cifra = new SimpleCrypt(Q_UINT64_C(0x0c2ad4c2acb9f023));
        nombre_cifrado = cifra->encryptToString(nombre);
        clave_cifrado = cifra->encryptToString(clave);
        QFile file(fichero);
        file.setPermissions(QFile::ReadOther | QFile::WriteOther);
        if (file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
           QTextStream out(&file);
           out << nombre_cifrado << "\n";
           out << clave_cifrado << "\n";
           file.close();
        }
    }
return 0;
}
