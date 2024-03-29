#ifndef DECORS_HPP
# define DECORS_HPP

#include "GameLoop.hpp"

class Decors: public AEntity{
    private:
        static std::string const  spritePool[4][7];
        bool                      _footer;

        Decors( void ); 

    public:
        Decors( bool footer, float Xpos, float Ypos );
        Decors(Decors &src);
        ~Decors(void);

        Decors &operator=(Decors const &rhs);

        virtual void 		update( void );
};

#endif