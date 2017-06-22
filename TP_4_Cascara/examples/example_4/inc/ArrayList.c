#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    void* auxElements;


    if(pList!=NULL && pElement!=NULL)
    {
        if(pList->size==pList->reservedSize)
        {
            auxElements = (void*) realloc(pList->pElements,sizeof(void*)*(pList->reservedSize + AL_INCREMENT));
            if(auxElements!=NULL)
            {
                pList->pElements = auxElements;
                pList->reservedSize +=AL_INCREMENT;

            }

        }
        pList->pElements[pList->size]=pElement;
        pList->size++;
        returnAux=0;

    }



    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL)
    {
        free(pList);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int returnAux = -1;

    if(this!=NULL)
    {
        returnAux=this->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList, int index)
{
    void* returnAux = NULL;

    if(pList!=NULL&&index<pList->size && index>=0&&pList->size<pList->reservedSize)
    {
        returnAux = pList->pElements[index];
    }


    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i;

    if(pList!=NULL&&pElement!=NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            if(pElement==pList->pElements[i])
            {
                returnAux = 1;
                break;
            }
            else
            {
                returnAux = 0;
            }
        }
    }



    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int returnAux = -1;

    if (pList!=NULL && pElement!=NULL)
    {
        if(index>=0&&index<=pList->size)//le quite el igual al pList
        {
            pList->pElements[index]=pElement;
            returnAux=0;
        }

    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    int returnAux = -1;
    //int i;

    /*void* auxElements;

    if(pList!=NULL&&index>=0)
    {
        for(i = index; i < pList->size - 1; i++)
        {
            pList->pElements[i] = pList->pElements[i + 1];

        }
        auxElements = (void*) realloc(pList->pElements,sizeof(void*)*(pList->reservedSize-1));
        if(auxElements!=NULL)
        {
            pList->pElements = auxElements;
            pList->reservedSize -1;


        }


        pList->size--;*/

        if(pList!=NULL&&index>=0 && index<=pList->size)
        {
            returnAux=contract(pList,index);
        }


    //}



    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int returnAux = -1;//pasar size a 0,y reservedsize a 10,y hacer un realloc si es necesario(resizeDown)
    void *auxElements;

    if(pList!=NULL)
    {
        pList->size=0;
        pList->reservedSize=10;
        auxElements = (void*) realloc(pList->pElements,sizeof(void*)*(AL_INITIAL_VALUE));
        pList->pElements = auxElements;
        return 0;

    }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;
    int i;

    /*if(this!=NULL)
    {
        returnAux=al_newArrayList();
    }*/



    if(this!=NULL)
    {
        returnAux=al_newArrayList();

       for(i=0;i<this->size;i++)
       {
          returnAux->reservedSize=this->reservedSize;
          returnAux->size=this->size;
          returnAux->pElements[i]=this->pElements[i];

       }
    }



    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int returnAux = -1;
    int i;


    if(pList!=NULL&&index>=0&&pElement!=NULL&&index<=pList->size&&pList->size<pList->reservedSize)
    {
        if(index==pList->size)
        {
           returnAux=al_add(pList,pElement);
        }
        if(index!=pList->size)
        {
           returnAux=expand(pList,index);
           returnAux=al_set(pList,index,pElement);

        }





    }




    /*if(pList!=NULL&&pElement!=NULL&&(index>=0&&index<=pList->size))
    {
        if(expand(pList,index))
        {
            al_set(pList,index,pElement);
            returnAux=0;
        }
    }
    else if(pList!=NULL&&pElement!=NULL&&(index>=0&&index==pList->size))
    {
       al_set(pList,index,pElement);
       returnAux=0;
    }/*


    /*if(pList!=NULL&&pElement!=NULL&&index>=0&&index<pList->size)
    {
        if(pList->size<pList->reservedSize)
        {
            expand(pList,index);

            for(i = index; i < pList->size; i++)
            {
               pList->pElements[i + 1] = pList->pElements[i];

            }

            returnAux=0;
        }
    }*/

    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i;

    if(pList!=NULL&&pElement!=NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            if(pElement == pList->pElements[i])
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
    int returnAux = -1;


    if(pList!=NULL)
    {

        if(pList->size==0)
        {
            return 1;
        }
        if(pList->size!=0)
        {
            return 0;
        }


    }




    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* returnAux = NULL;

    if(pList!=NULL&&pList->pElements!=NULL&&index<pList->size&&index>=0)
    {
       // if(pList->size<pList->reservedSize)

            returnAux = al_get(pList,index);

            al_remove(pList,index);



    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    int i;
    ArrayList* returnAux = NULL;
    returnAux = al_newArrayList();

    if((pList != NULL && returnAux != NULL && pList->pElements != NULL) && (from >= 0) && (to >= 0) && (from <= pList->size) && (to <= pList->size) && (to >= from))
    {
        for(i = from; i <= to; i++)
        {
            returnAux->pElements[i] = pList->pElements[i];
        }
        returnAux->size = i;
        returnAux->reservedSize = i + AL_INITIAL_VALUE;
    }
    else
    {
        returnAux = NULL;
    }
    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int returnAux = -1;
    int i;


    if(pList!=NULL&&pList2!=NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            if(pList->pElements[i]==pList2->pElements[i])
            {
                returnAux = 1;
                break;
            }
            else
            {
                returnAux = 0;
            }
        }
    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void*,void*), int order)
{
    int returnAux = -1;
    int i;
    int j;
    void* auxElement;

    if(pList!=NULL&&pFunc!=NULL)
    {
        if(order==1||order==0)
        {
            for(i=0; i<pList->size-1; i++)
            {
                for(j=i+1; j<pList->size; j++)
                {
                     if(order==0)
                     {
                        if(pFunc(al_get(pList,i),al_get(pList,j))<0)
                        {
                            auxElement=pList->pElements[i];
                            pList->pElements[i]=pList->pElements[j];
                            pList->pElements[j]=auxElement;
                            returnAux=0;
                        }
                     }
                     if(order==1)
                     {
                        if(pFunc(al_get(pList,i),al_get(pList,j))>0)
                        {
                            auxElement=pList->pElements[i];
                            pList->pElements[i]=pList->pElements[j];
                            pList->pElements[j]=auxElement;
                            returnAux=0;
                        }
                     }


                }
            }


        }


    }

    return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{
    int returnAux = -1;
    void* auxElements;

    if(pList!=NULL)
    {
        auxElements = (void*) realloc(pList->pElements,sizeof(void*)*(pList->reservedSize + AL_INCREMENT));
         if(auxElements!=NULL)
         {
                pList->pElements = auxElements;
                pList->reservedSize +=AL_INCREMENT;

          }


        return 0;

    }

    return returnAux;

}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int returnAux = -1;
    int i;

    if(pList!=NULL&&index>0)
    {
        if(pList->size<pList->reservedSize)
        {
            pList->size++;

            for(i=index;i<pList->size;i++)
            {
                pList->pElements[i+1]=pList->pElements[i];
            }
            returnAux=0;
        }
    }


    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1;
    int i;

    if(pList!=NULL&&index>=0&&index<pList->size)
    {

        for(i=index;i<(pList->size)-1;i++)
        {
            pList->pElements[i]=pList->pElements[i+1];
        }

        pList->size--;
        returnAux=0;
    }

    return returnAux;
}
