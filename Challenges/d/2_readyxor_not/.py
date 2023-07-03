import base64

data_o = "El Psy Congroo"
data_e = "IFhiPhZNYi0KWiUcCls="
flag = "I3gDKVh1Lh4EVyMDBFo="

data_o = base64.b64decode(flag).decode("ascii")
