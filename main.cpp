#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include "simplecrypt.h"
#include <QDir>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString nombre,nombre_cifrado;
    QString clave,clave_cifrado;
    QString fichero=QDir::homePath()+"/.grx/.proxy";

    if (argc > 2)
    {
        if (!QDir(QDir::homePath()+"/.grx").exists()){
            QDir().mkdir(QDir::homePath()+"/.grx");
        }

        SimpleCrypt *cifra = new SimpleCrypt(Q_UINT64_C(0x0c2ad4c2acb9f023));
        nombre = a.arguments().at(1);
        clave = a.arguments().at(2);
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
