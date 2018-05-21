//
//  Undo.cpp
//  TestLab11
//
//  Created by Adrian-Paul Florea on 5/17/18.
//  Copyright © 2018 Adrian-Paul Florea. All rights reserved.
//

#include "Undo.h"
#include <iostream>

void UndoAddOperation::executeUndo(){
    paintingRepo.removePainting(this->p);
    
}

void UndoMoveOperation::executeUndo(){
    paintingRepo.addPaintintg(this->p);
    specialRepo.removePainting(this->p);
}

