# grx-proxy
Creamos una entrada de pam en auth-common, para capturar el nombre de usuario y su clave.
Creamos un archivo con el nombre y la clave cifrada del usuario que se identifica sólo por sddm.
Nos sirve en el paquete grx-dbus para mandar el usuario y la clave al proxy ntlmv2.
Pero tambien puede servir para cualquier paquete que necesite la clave del usuario sin necesidad de pedírsela repetidamente.
