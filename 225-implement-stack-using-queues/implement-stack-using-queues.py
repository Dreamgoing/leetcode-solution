# coding=utf-8

class MyStack(object):
    def __init__(self):
        self.queue_l = []
        self.queue_r = []
        self.top_item = None

    def push(self, x):
        self.top_item = x
        if len(self.queue_l) == 0 and len(self.queue_r) == 0:
            self.queue_l.append(x)
        elif len(self.queue_l):
            self.queue_l.append(x)
        elif len(self.queue_r):
            self.queue_r.append(x)

    def pop(self):
        if len(self.queue_l):
            while len(self.queue_l) > 1:
                tmp = self.queue_l.pop(0)
                self.queue_r.append(tmp)
                self.top_item = tmp
            return self.queue_l.pop(0)
        elif len(self.queue_r):
            while len(self.queue_r) > 1:
                tmp = self.queue_r.pop(0)
                self.queue_l.append(tmp)
                self.top_item = tmp
            return self.queue_r.pop(0)

    def top(self):
        return self.top_item


    def empty(self):
        return len(self.queue_l) == 0 and len(self.queue_r) == 0
