/********************************************************************
 *             a  A                                                        
 *            AM\/MA                                                         
 *           (MA:MMD                                                         
 *            :: VD
 *           ::  º                                                         
 *          ::                                                              
 *         ::   **      .A$MMMMND   AMMMD     AMMM6    MMMM  MMMM6             
 +       6::Z. TMMM    MMMMMMMMMDA   VMMMD   AMMM6     MMMMMMMMM6            
 *      6M:AMMJMMOD     V     MMMA    VMMMD AMMM6      MMMMMMM6              
 *      ::  TMMTMC         ___MMMM     VMMMMMMM6       MMMM                   
 *     MMM  TMMMTTM,     AMMMMMMMM      VMMMMM6        MMMM                  
 *    :: MM TMMTMMMD    MMMMMMMMMM       MMMMMM        MMMM                   
 *   ::   MMMTTMMM6    MMMMMMMMMMM      AMMMMMMD       MMMM                   
 *  :.     MMMMMM6    MMMM    MMMM     AMMMMMMMMD      MMMM                   
 *         TTMMT      MMMM    MMMM    AMMM6  MMMMD     MMMM                   
 *        TMMMM8       MMMMMMMMMMM   AMMM6    MMMMD    MMMM                   
 *       TMMMMMM$       MMMM6 MMMM  AMMM6      MMMMD   MMMM                   
 *      TMMM MMMM                                                           
 *     TMMM  .MMM                                         
 *     TMM   .MMD       ARBITRARY·······XML········RENDERING                           
 *     TMM    MMA       ====================================                              
 *     TMN    MM                               
 *      MN    ZM                       
 *            MM,
 *
 * 
 *      AUTHORS: Miro Keller
 *      
 *      COPYRIGHT: ©2011 - All Rights Reserved
 *
 *      LICENSE: see License.txt file
 *
 *      WEB: http://axr.vg
 *
 *      THIS CODE AND INFORMATION ARE PROVIDED "AS IS"
 *      WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED
 *      OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 *      IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR
 *      FITNESS FOR A PARTICULAR PURPOSE.
 *
 ********************************************************************
 *
 *      FILE INFORMATION:
 *      =================
 *      Last changed: 2011/04/16
 *      HSS version: 1.0
 *      Core version: 0.3
 *      Revision: 6
 *
 ********************************************************************/

#ifndef HSSDISPLAYOBJECT_H
#define HSSDISPLAYOBJECT_H

#include <string>
#include <map>
#include <vector>
#include "HSSObject.h"
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include "../parsing/HSSRule.h"

namespace AXR {
    
    class HSSContainer;

    class HSSDisplayObject : public HSSObject
    {
    public:
        typedef boost::shared_ptr<HSSDisplayObject> p;
        typedef boost::weak_ptr<HSSContainer> parentPointer;
        
        HSSDisplayObject();
        HSSDisplayObject(std::string name);
        virtual ~HSSDisplayObject();
        virtual std::string toString();
        virtual std::string defaultObjectType(std::string property);
        virtual bool isKeyword(std::string value, std::string property);
        boost::shared_ptr<HSSContainer> getParent();
        void setParent(boost::shared_ptr<HSSContainer> parent);
        void attributesAdd(std::string name, std::string value);
        void attributesRemove(std::string name);
        
        void rulesAdd(HSSRule::p newRule);
        HSSRule::p rulesGet(unsigned index);
        void rulesRemove(unsigned index);
        void rulesRemoveLast();
        const int rulesSize();
        
        std::string getElementName();
        void setElementName(std::string name);
        
        
    protected:
        parentPointer parent;
        std::map<std::string, std::string>attributes;
        std::string elementName;
        std::string contentText;
        std::vector<HSSRule::p> rules;
        
        //here go the final computed values
        double x;
        double y;
        double height;
        double width;
        //FIXME: bounds
        double anchorX;
        double anchorY;
        bool flow;
        bool does_float;
        double alignX;
        double alignY;
        //FIXME: margin
        //FIXME: border
        double zoomFactor;
        //FIXME: transform
        //FIXME: effects
        //FIXME: animation
        //FIXME: behavior
        bool visible;
        signed int drawIndex;
        unsigned int tabIndex;
        //FIXME: focused
        //FIXME: mask
        
        //here go the definition objects
        HSSObject::p d_width;
        HSSObject::p d_height;

    };

}


#endif