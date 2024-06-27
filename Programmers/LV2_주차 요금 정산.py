import math

def calcParkingFee(parking_time, default_time, default_fee, unit_time, unit_fee):
    if parking_time <= default_time:
        return default_fee
    else:
        addition = math.ceil((parking_time - default_time) / unit_time) * unit_fee
        return default_fee + addition

def solution(fees, records):
    default_time, default_fee, unit_time, unit_fee = fees
    cars = {}
    
    for record in records:
        time, car_number, history = record.split(" ")
        
        if history == "IN":
            if car_number not in cars:
                target = Car(car_number, time)
                cars[car_number] = target
            else:
                target = cars[car_number]
                target.re_entry(time)
        elif history == "OUT":
            target = cars[car_number]
            target.departure(time)
        else:
            print("Wrong History")
    
    answer = []
    for _, car in sorted(cars.items()):
        if car.isParked():
            car.departure()
        pt = car.total_parking_time
        parking_fee = calcParkingFee(pt, default_time, default_fee, unit_time, unit_fee)
        answer.append(parking_fee)
        
    return answer

class Car: 
    def __init__(self, car_number, entry_time):
        self.car_number = car_number
        self.entry_time = entry_time
        self.departure_time = None
        self.total_parking_time = 0
    
    def re_entry(self, time):
        self.entry_time = time
        
    def departure(self, time=None):
        if time is None:
            time = "23:59"
        self.departure_time = time
        self.__update_parking_time()
        self.__reset_time()
    
    def isParked(self):
        return True if self.entry_time is not None and self.departure_time is None else False
    
    def __update_parking_time(self):
        dep_h, dep_m = map(int, self.departure_time.split(":"))
        ent_h, ent_m = map(int, self.entry_time.split(":"))
        total_minute = (dep_h - ent_h) * 60 + dep_m - ent_m
        self.total_parking_time += total_minute
    
    def __reset_time(self):
        self.entry_time = None
        self.departure_time = None
        

"""
최종 목표: 청구할 주차요금을 차량번호를 기준으로 오름차순으로 정렬해 반환

자동차 - 차량번호, 입차시간, 출차시간 존재
자동차의 출차시간이 존재하지 않을 수 있음 - 그때는 23:59 출차로 간주
하루 내에 자동차는 여러번 입출차를 반복할 수 있음
누적 시간을 기준으로 하루의 마지막에 요금을 한번에 정산

요금 정산
1. 기본 시간 이하 주차 = 기본 요금
2. 기본 시간 초과 주차 = 기본 요금 + [(누적 주차시간-기본시간) / 단위시간](올림) * 단위 요금
"""