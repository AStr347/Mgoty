import xlsxwriter

'''
	Строки
    5. Даны сведения о рабочих: табельный номер, Ф.И.О., год рождения, пол,
	стаж работы, разряд рабочего, номер цеха, номер участка, сумма заработной платы. Вывести входные данные в виде табл. 1.10.
	Таблица 1.10
'''

class worker():
    def __init__(self, s:str):
        # табельный номер, Ф.И.О., год рождения, пол, 
        # стаж работы, разряд рабочего, номер цеха, номер участка, сумма заработной платы.
        data = s.split()
        self.id = int(data[0])
        self.fio = f"{data[1]} {data[2]} {data[3]}"
        self.year = int(data[4])
        self.male = data[5]
        self.wyear = int(data[6])
        self.r = int(data[7])
        self.nc = int(data[8])
        self.ny = int(data[9])
        self.zp = int(data[10])

class ych_data():
    def __init__(self, _ny:int, l:list[worker]):
        self.ny = _ny
        self.count = len(l)
        self.counts = [0,0,0]
        zp = 0
        for i in l:
            zp += i.zp
            self.counts[i.r-1] += 1

        self.sr_zp = zp / self.count


if(__name__ == "__main__"):
    workbook = xlsxwriter.Workbook("1.xlsx")
    
    # Create a format
    cell_format = workbook.add_format()
    cell_format.set_text_wrap(True)
    cell_format.set_align("center")
    cell_format.set_align("vcenter")
    cell_format.set_border(1)

    worksheet = workbook.add_worksheet()
    #set row height and columns format
    worksheet.set_row(0, 40)
    worksheet.set_column("A:F", cell_format = cell_format)
    
    #set header data
    worksheet.merge_range("A1:A2", "№ участка", cell_format)
    worksheet.merge_range("B1:B2", "Средняя зп", cell_format)
    worksheet.merge_range("C1:C2", "Всего", cell_format)
    worksheet.merge_range("D1:F1", "Количество рабочих\nВ том числе по разрядам", cell_format)
    worksheet.write("D2", 1, cell_format)
    worksheet.write("E2", 2, cell_format)
    worksheet.write("F2", 3, cell_format)

    #read data from file
    f = open('w.txt', 'r', encoding="utf8")
    lines = f.readlines()
    workers = []
    ych = set()
    for i in lines:
        w = worker(i)
        ych.add(w.ny)
        workers.append(w)
    
    f.close()

    #processes data about plots
    ychs = []
    for i in ych:
        wl = list(filter(lambda w: w.ny == i, workers))
        ychs.append(ych_data(i, wl))

    offset = 3
    #fill plots data to excel
    for i,v in enumerate(ychs):
        worksheet.write(f"A{i+offset}", v.ny)
        worksheet.write(f"B{i+offset}", v.sr_zp)
        worksheet.write(f"C{i+offset}", v.count)
        worksheet.write(f"D{i+offset}", v.counts[0])
        worksheet.write(f"E{i+offset}", v.counts[1])
        worksheet.write(f"F{i+offset}", v.counts[2])
    
    
    workbook.close()