class MyCalendarTwo {
public:
    // Vectores para eventos simples y dobles reservas
    vector<pair<int, int>> events;
    vector<pair<int, int>> doublebooking;

    MyCalendarTwo() { }
    
    bool book(int start, int end) {
        // Verificamos si se cruza con alguna doble reserva
        for (auto& p : doublebooking) {
            if (start < p.second && end > p.first) {
                return false;  // Si hay un cruce, no se puede reservar
            }
        }
        
        // Buscamos eventos con los que se cruza y los agregamos a las dobles reservas
        for (auto& p : events) {
            if (start < p.second && end > p.first) {
                doublebooking.push_back({max(start, p.first), min(end, p.second)});
            }
        }
        
        // Finalmente, agregamos el evento
        events.push_back({start, end});
        return true;  // La reserva es válida
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start, end);
 */
