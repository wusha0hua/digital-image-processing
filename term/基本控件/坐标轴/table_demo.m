function varargout = table_demo(varargin)
%TABLE_DEMO M-file for table_demo.fig
%      TABLE_DEMO, by itself, creates a new TABLE_DEMO or raises the existing
%      singleton*.
%
%      H = TABLE_DEMO returns the handle to a new TABLE_DEMO or the handle to
%      the existing singleton*.
%
%      TABLE_DEMO('Property','Value',...) creates a new TABLE_DEMO using the
%      given property value pairs. Unrecognized properties are passed via
%      varargin to table_demo_OpeningFcn.  This calling syntax produces a
%      warning when there is an existing singleton*.
%
%      TABLE_DEMO('CALLBACK') and TABLE_DEMO('CALLBACK',hObject,...) call the
%      local function named CALLBACK in TABLE_DEMO.M with the given input
%      arguments.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help table_demo

% Last Modified by GUIDE v2.5 07-Nov-2015 17:27:48

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @table_demo_OpeningFcn, ...
                   'gui_OutputFcn',  @table_demo_OutputFcn, ...
                   'gui_LayoutFcn',  [], ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
   gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before table_demo is made visible.
function table_demo_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   unrecognized PropertyName/PropertyValue pairs from the
%            command line (see VARARGIN)

% Choose default command line output for table_demo
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes table_demo wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = table_demo_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;


% --- Executes during object creation, after setting all properties.
function uitable_GrayComatrix_CreateFcn(hObject, eventdata, handles)
% hObject    handle to uitable_GrayComatrix (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% --- Executes on button press in push_ComputeComatrix.
function push_ComputeComatrix_Callback(hObject, eventdata, handles)
% hObject    handle to push_ComputeComatrix (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
