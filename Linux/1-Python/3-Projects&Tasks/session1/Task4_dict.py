CANData={
"Start":"01011010",
"Arbitration":0,
"Control field":0b0101,
"Data field":0b01101100,
"CRC field" :1,
"Ack field":1,
"End of frame":1111

}
data_list=[]
print(CANData)
frame=(input("select the frame you need"))
for n in CANData:
    if (n==frame):
        print(CANData[n])
        data_list.extend(CANData[n])
        print(data_list)
        data_list.clear()
        break